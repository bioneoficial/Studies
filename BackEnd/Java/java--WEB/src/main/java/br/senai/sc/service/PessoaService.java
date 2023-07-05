package br.senai.sc.service;

import br.senai.sc.dao.PessoaDAO;
import br.senai.sc.model.Pessoa;

import javax.inject.Inject;
import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;
import javax.transaction.Transactional;

public class PessoaService {
    @PersistenceContext
    private EntityManager entityManager;
    @Inject
    private PessoaDAO pessoaDAO;

    public void salvar(Pessoa pessoa) {
        pessoaDAO.salvar(pessoa);
    }

    public void atualizar(Pessoa pessoa) {
        pessoaDAO.atualizar(pessoa);
    }

    public void criarPessoa(Pessoa pessoa) {
        entityManager.persist(pessoa);
    }
}
