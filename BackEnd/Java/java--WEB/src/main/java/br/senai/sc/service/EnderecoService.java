package br.senai.sc.service;

import br.senai.sc.dao.EnderecoDAO;
import br.senai.sc.model.Endereco;

import javax.inject.Inject;
import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;
import javax.transaction.Transactional;

public class EnderecoService {

    @PersistenceContext
    private EntityManager entityManager;
    @Inject
    private EnderecoDAO enderecoDAO;

    public void salvar(Endereco endereco) {
        enderecoDAO.salvar(endereco);
    }

    public void atualizar(Endereco endereco) {
        enderecoDAO.atualizar(endereco);
    }


    public void criarEndereco(Endereco endereco) {

    }
}
