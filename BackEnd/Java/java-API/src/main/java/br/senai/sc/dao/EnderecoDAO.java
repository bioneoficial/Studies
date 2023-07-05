package br.senai.sc.dao;

import br.senai.sc.model.Endereco;

import javax.inject.Inject;
import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;
import javax.transaction.UserTransaction;

public class EnderecoDAO {
    @PersistenceContext(name = "prova-java")
    private EntityManager entityManager;

    @Inject
    private UserTransaction userTransaction;

    public void create(Endereco endereco) {
        entityManager.persist(endereco);
    }

    public void update(Endereco endereco) {
        try{
            userTransaction.begin();
            entityManager.merge(endereco);
            userTransaction.commit();

        }catch (Exception e){
            try {
                userTransaction.rollback();
            } catch (Exception rollbackException) {
                throw new RuntimeException("Falha ao reverter a transação", rollbackException);
            }
            throw new RuntimeException("Erro ao atualizar pessoa", e);
        }

    }

    public Endereco findById(Integer id) {
        return entityManager.find(Endereco.class, id);
    }

    public void deleteById(Integer id) {
        Endereco endereco = findById(id);
        if (endereco != null) {
            try {
                userTransaction.begin();
                entityManager.remove(endereco);
                userTransaction.commit();
            } catch (Exception e) {
                e.printStackTrace();
                try {
                    userTransaction.rollback();
                } catch (Exception ex) {
                    ex.printStackTrace();
                }
            }
        }
    }
}