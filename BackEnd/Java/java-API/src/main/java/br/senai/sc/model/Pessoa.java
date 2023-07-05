package br.senai.sc.model;

import br.senai.sc.util.DataConverter;

import javax.json.bind.annotation.JsonbProperty;
import javax.json.bind.annotation.JsonbTransient;
import javax.json.bind.annotation.JsonbTypeAdapter;
import javax.persistence.*;
import java.util.Date;

@Entity
@Table(name = "pessoa")
public class Pessoa {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Integer idPessoa;

    @Column(name = "criacao_registro")
    @Temporal(TemporalType.TIMESTAMP)
    protected Date criacaoRegistro;

    @Column(name = "alteracao_registro")
    @Temporal(TemporalType.TIMESTAMP)
    private Date alteracaoRegistro;

    @Column(name = "nome")
    private String nome;

    @Column(name = "nascimento")
    @Temporal(TemporalType.DATE)
    @JsonbTypeAdapter(DataConverter.DateDeserializer.class)
    private Date nascimento;

    @Column(name = "cpf")
    private String cpf;

    @Column(name = "email")
    private String email;


    @OneToOne(cascade = CascadeType.ALL)
    @JoinColumn(name = "idPessoa")
    private Endereco endereco;

public Integer getIdPessoa() {
        return idPessoa;
    }

    public void setIdPessoa(Integer id) {
        this.idPessoa = id;
    }

    public Date getCriacaoRegistro() {
        return criacaoRegistro;
    }

    public void setCriacaoRegistro(Date criacaoRegistro) {
        this.criacaoRegistro = criacaoRegistro;
    }

    public Date getAlteracaoRegistro() {
    if(alteracaoRegistro == null){
        return criacaoRegistro;
    }
        return alteracaoRegistro;
    }

    public void setAlteracaoRegistro(Date alteracaoRegistro) {
        this.alteracaoRegistro = alteracaoRegistro;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public Date getNascimento() {
        return nascimento;
    }

    public void setNascimento(Date nascimento) {
        this.nascimento = nascimento;
    }

    public String getCpf() {
        return cpf;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public Endereco getEndereco() {
        return endereco;
    }

    public void setEndereco(Endereco endereco) {
        this.endereco = endereco;
    }
}
