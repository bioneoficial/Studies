package br.senai.sc.model;

import javax.json.bind.annotation.JsonbTransient;
import javax.persistence.*;

@Entity
@Table(name = "endereco")
public class Endereco {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Integer idEndereco;

    @Column(name = "cep")
    private String cep;

    @Column(name = "rua")
    private String rua;

    @Column(name = "numero")
    private Integer numero;

    @Column(name = "cidade")
    private String cidade;

    @Column(name = "estado")
    private String estado;

    @Column(name = "id_pessoa", insertable = false, updatable = false)
    private Integer idPessoa;

    @OneToOne
    @JoinColumn(name = "id_pessoa", referencedColumnName = "idPessoa")
    private Pessoa pessoa;

    public Integer getIdEndereco() {
        return idEndereco;
    }

    public void setIdEndereco(Integer id) {
        this.idEndereco = id;
    }
    public Integer getIdPessoa() {
        return idPessoa;
    }

    public void setIdPessoa(Integer idPessoa) {
        this.idPessoa = idPessoa;
    }

    public String getCep() {
        return cep;
    }

    public void setCep(String cep) {
        this.cep = cep;
    }

    public String getRua() {
        return rua;
    }

    public void setRua(String rua) {
        this.rua = rua;
    }

    public Integer getNumero() {
        return numero;
    }

    public void setNumero(Integer numero) {
        this.numero = numero;
    }

    public String getCidade() {
        return cidade;
    }

    public void setCidade(String cidade) {
        this.cidade = cidade;
    }

    public String getEstado() {
        return estado;
    }

    public void setEstado(String estado) {
        this.estado = estado;
    }

    @JsonbTransient
    public Pessoa getPessoa() {
        return pessoa;
    }

    public void setPessoa(Pessoa pessoa) {
        this.pessoa = pessoa;
    }



}
