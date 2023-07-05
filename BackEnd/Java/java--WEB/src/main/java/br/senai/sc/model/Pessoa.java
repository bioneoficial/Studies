package br.senai.sc.model;

import java.time.LocalDate;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.OneToOne;

@Entity
public class Pessoa {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Integer idPessoa;
    private String nome;
    private LocalDate nascimento;
    private String cpf;
    private String email;

    @OneToOne(mappedBy = "pessoa")
    private Endereco endereco;

    private String situacaoIntegracao;

    public Pessoa(String nome, LocalDate nascimento, String cpf, String email, Endereco endereco) {
    }

    public Pessoa() {

    }

    public Integer getIdPessoa() {
        return idPessoa;
    }

    public void setIdPessoa(Integer idPessoa) {
        this.idPessoa = idPessoa;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public LocalDate getNascimento() {
        return nascimento;
    }

    public void setNascimento(LocalDate nascimento) {
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

    public String getSituacaoIntegracao() {
        return situacaoIntegracao;
    }

    public void setSituacaoIntegracao(String situacaoIntegracao) {
        this.situacaoIntegracao = situacaoIntegracao;
    }
}
