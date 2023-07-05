package br.senai.sc.dao;

import br.senai.sc.model.Pessoa;

import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;

public class PessoaDAO {

    @PersistenceContext
    private EntityManager entityManager;

    public void salvar(Pessoa pessoa) {
        entityManager.persist(pessoa);
    }

    public void atualizar(Pessoa pessoa) {
        entityManager.merge(pessoa);
    }
}
