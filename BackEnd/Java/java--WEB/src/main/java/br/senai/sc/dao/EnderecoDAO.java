package br.senai.sc.dao;

import br.senai.sc.model.Endereco;

import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;

public class EnderecoDAO {

    @PersistenceContext
    private EntityManager entityManager;

    public void salvar(Endereco endereco) {
        entityManager.persist(endereco);
    }

    public void atualizar(Endereco endereco) {
        entityManager.merge(endereco);
    }
}
