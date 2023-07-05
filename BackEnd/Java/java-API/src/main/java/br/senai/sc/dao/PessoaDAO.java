package br.senai.sc.dao;

import br.senai.sc.model.Pessoa;

import javax.enterprise.context.ApplicationScoped;
import javax.inject.Inject;
import javax.persistence.EntityManager;
import javax.persistence.NoResultException;
import javax.persistence.PersistenceContext;
import javax.transaction.Status;
import javax.transaction.SystemException;
import javax.transaction.UserTransaction;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

@ApplicationScoped
public class PessoaDAO {
    @PersistenceContext(name = "prova-java")
    private EntityManager entityManager;


    @Inject
    private UserTransaction userTransaction;

    private static final Logger LOGGER = Logger.getLogger(PessoaDAO.class.getName());
    public void create(Pessoa pessoa) {
        try {
            userTransaction.begin();
            entityManager.persist(pessoa);
            userTransaction.commit();
        } catch (Exception e) {
            System.err.println("Erro de persistência: " + e.getMessage());
            rollbackTransaction();
        }
        }

    private void rollbackTransaction() {
        try {
            if (userTransaction.getStatus() != Status.STATUS_NO_TRANSACTION) {
                userTransaction.rollback();
            }
        } catch (SystemException e) {
            System.err.println("Erro ao fazer rollback: " + e.getMessage());
        }
    }


    public void update(Pessoa pessoa) {
try{
    userTransaction.begin();
    entityManager.merge(pessoa);
    userTransaction.commit();

}catch (Exception e){
    try {
        userTransaction.rollback();
    } catch (Exception rollbackException) {
        LOGGER.log(Level.SEVERE, "Falha ao reverter a transação", rollbackException);
    }
    LOGGER.log(Level.SEVERE, "Erro ao atualizar pessoa", e);
    throw new RuntimeException("Erro ao atualizar pessoa", e);
}
    }

    public Pessoa findByCPF(String cpf) {
        try {
            return entityManager.createQuery("SELECT p FROM Pessoa p WHERE p.cpf = :cpf", Pessoa.class)
                    .setParameter("cpf", cpf)
                    .getSingleResult();
        } catch (NoResultException e) {
            return null;
        }
    }

    public List<Pessoa> findAll() {
        return entityManager.createQuery("SELECT p FROM Pessoa p", Pessoa.class).getResultList();
    }

    public void deleteByCPF(String cpf) {
        try {
            userTransaction.begin();
            Pessoa pessoa = findByCPF(cpf);
            if (pessoa != null) {
                pessoa = entityManager.merge(pessoa);
                entityManager.remove(pessoa);
            }
            userTransaction.commit();
        } catch (Exception e) {
            try {
                userTransaction.rollback();
            } catch (Exception rollbackException) {
                LOGGER.log(Level.SEVERE, "Falha ao reverter a transação", rollbackException);
            }
            LOGGER.log(Level.SEVERE, "Erro ao deletar pessoa por CPF", e);
        }
    }
}
