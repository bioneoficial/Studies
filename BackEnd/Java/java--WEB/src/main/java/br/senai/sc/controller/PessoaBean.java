package br.senai.sc.controller;

import br.senai.sc.model.Endereco;
import br.senai.sc.model.Pessoa;
import java.io.Serializable;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;
import javax.faces.application.FacesMessage;
import javax.faces.bean.ManagedBean;
import javax.faces.bean.ViewScoped;
import javax.faces.component.UIComponent;
import javax.faces.context.FacesContext;
import javax.faces.validator.Validator;
import javax.faces.validator.ValidatorException;
import javax.json.JsonObject;
import javax.ws.rs.client.Client;
import javax.ws.rs.client.ClientBuilder;
import javax.ws.rs.client.Entity;
import javax.ws.rs.client.WebTarget;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.Response;
@ManagedBean(name="PessoaBean")
@ViewScoped
public class PessoaBean implements Serializable {
    private String nome;
    private String nascimento;
    private String cpf;
    private String email;
    private String cep;
    private String rua;
    private String numero;
    private String cidade;
    private String estado;
    private String situacaoIntegracao;

    private final List<Pessoa> pessoas;
    private Object dataHoraInclusaoRegistro;
    private Object dataHoraUltimaAlteracaoRegistro;

    public PessoaBean() {
        pessoas = new ArrayList<>();
    }


    public List<Pessoa> getPessoas() {
        return pessoas;
    }

    public void setRua(String rua) {
        this.rua = rua;
    }

    public String getRua() {
        return rua;
    }

    public void setCidade(String cidade) {
        this.cidade = cidade;
    }

    public String getCidade() {
        return cidade;
    }

    public void setEstado(String estado) {
        this.estado = estado;
    }

    public String getEstado() {
        return estado;
    }

    public void salvar() {
        if (isCpfCadastrado(cpf)) {
            FacesMessage message = new FacesMessage(FacesMessage.SEVERITY_ERROR, "CPF já cadastrado", null);
            FacesContext.getCurrentInstance().addMessage(null, message);
            return;
        }

        Pessoa pessoa = new Pessoa();
        pessoa.setNome(nome);
        pessoa.setNascimento(LocalDate.parse(nascimento));
        pessoa.setCpf(cpf);
        pessoa.setEmail(email);

        Endereco endereco = new Endereco();
        endereco.setRua(rua);
        endereco.setNumero(Integer.valueOf(numero));
        endereco.setCidade(cidade);
        endereco.setEstado(estado);
        pessoa.setEndereco(endereco);

        // Integração com a API
        boolean isIntegrado = integrarPessoa(pessoa);
        if (isIntegrado) {
            pessoa.setSituacaoIntegracao("Integrado");
        } else {
            pessoa.setSituacaoIntegracao("Não integrado");
        }

        pessoas.add(pessoa);
    }

    private boolean isCpfCadastrado(String cpf) {
        for (Pessoa p : pessoas) {
            if (p.getCpf().equals(cpf)) {
                return true;
            }
        }
        return false;
    }

    public boolean integrarPessoa(Pessoa pessoa) {
        if (pessoa == null || pessoa.getNome() == null || pessoa.getNascimento() == null || pessoa.getCpf() == null || pessoa.getEmail() == null || pessoa.getEndereco() == null) {
            return false;
        }
        Endereco endereco = pessoa.getEndereco();
        if (endereco.getRua() == null || endereco.getNumero() == null || endereco.getCidade() == null || endereco.getEstado() == null) {
            return false;
        }

        String url = "http://localhost:8081/prova-java-remoto/pessoas";
        Client client = ClientBuilder.newClient();
        Response response = client.target(url)
                .request(MediaType.APPLICATION_JSON)
                .post(Entity.entity(pessoa, MediaType.APPLICATION_JSON));

        return response.getStatus() == 201;
    }

    public void validateName(FacesContext context, UIComponent component, Object value) throws ValidatorException {
        String nome = value.toString();
        String[] partesNome = nome.split(" ");

        if (partesNome.length < 2) {
            throw new ValidatorException(new FacesMessage("O nome deve conter pelo menos dois nomes."));
        }

        for (String parte : partesNome) {
            if (!Character.isUpperCase(parte.charAt(0))) {
                throw new ValidatorException(new FacesMessage("A primeira letra de cada nome deve ser maiúscula."));
            }
        }
    }

    public void preencherEndereco() {
        JsonObject enderecoJson = ViaCEP.getEndereco(this.cep);
        if (enderecoJson != null) {
            this.setRua(enderecoJson.getString("logradouro"));
            this.setCidade(enderecoJson.getString("localidade"));
            this.setEstado(enderecoJson.getString("uf"));
        } else {
            this.setRua("Não encontrado");
            this.setCidade("Não encontrado");
            this.setEstado("Não encontrado");
        }
    }


    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setNascimento(String nascimento) {
        this.nascimento = nascimento;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public void setCep(String cep) {
        this.cep = cep;
    }

    public void setNumero(String numero) {
        this.numero = numero;
    }

    public String getNome() {
        return nome;
    }

    public String getNascimento() {
        return nascimento;
    }

    public String getCpf() {
        return cpf;
    }

    public String getEmail() {
        return email;
    }

    public String getCep() {
        return cep;
    }

    public String getNumero() {
        return numero;
    }

    public String getSituacaoIntegracao() {
        return situacaoIntegracao;
    }

    public void setSituacaoIntegracao(String situacaoIntegracao) {
        this.situacaoIntegracao = situacaoIntegracao;
    }

    public void consultar() {
        String url = "http://localhost:8081/prova-java-remoto/pessoas";

        Client client = ClientBuilder.newClient();
        WebTarget target = client.target(url).queryParam("cpf", cpf);

        Response response = target.request(MediaType.APPLICATION_JSON).get();

        if (response.getStatus() == 200) {
            JsonObject jsonResponse = response.readEntity(JsonObject.class);
            JsonObject pessoaJson = jsonResponse.getJsonObject("pessoa");

            // Converte o JsonObject para um objeto Pessoa
//            pessoaConsulta = convertJsonObjectToPessoa(pessoaJson);
//
//            Armazena as informações de data e hora
//            dataHoraInclusaoRegistro = jsonResponse.getString("dataHoraInclusaoRegistro");
//            dataHoraUltimaAlteracaoRegistro = jsonResponse.getString("dataHoraUltimaAlteracaoRegistro");
        } else {
            // Trate os casos de erro aqui
        }
    }

    private Pessoa convertJsonObjectToPessoa(JsonObject jsonObject) {
        String nome = jsonObject.getString("nome");
        LocalDate nascimento = LocalDate.parse(jsonObject.getString("nascimento"));
        String cpf = jsonObject.getString("cpf");
        String email = jsonObject.getString("email");

        JsonObject enderecoJson = jsonObject.getJsonObject("endereco");
        String cep = enderecoJson.getString("cep");
        String rua = enderecoJson.getString("rua");
        Integer numero = enderecoJson.getInt("numero");
        String cidade = enderecoJson.getString("cidade");
        String estado = enderecoJson.getString("estado");

        Endereco endereco = new Endereco(cep, rua, numero, cidade, estado);
        return new Pessoa(nome, nascimento, cpf, email, endereco);
    }

    public Object getDataHoraInclusaoRegistro() {
        return dataHoraInclusaoRegistro;
    }

    public void setDataHoraInclusaoRegistro(Object dataHoraInclusaoRegistro) {
        this.dataHoraInclusaoRegistro = dataHoraInclusaoRegistro;
    }

    public Object getDataHoraUltimaAlteracaoRegistro() {
        return dataHoraUltimaAlteracaoRegistro;
    }
}
