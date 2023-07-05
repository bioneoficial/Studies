package br.senai.sc.dao;

import br.senai.sc.model.HelloWorld;

import javax.annotation.PostConstruct;
import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;

public class HelloWorldDao {
	
    @PersistenceContext(name = "prova-java")
    private EntityManager entityManager;
    
    public String getHelloWorldPhrase() {
    	HelloWorld helloWorld = entityManager.createQuery("FROM HelloWorld h", HelloWorld.class)
    	.setMaxResults(1)
    	.getSingleResult();
    	
    	return helloWorld.getPhrase();
    }
    
    @PostConstruct
    private void addPhrase() {
    	HelloWorld helloWorld = new HelloWorld();
    	helloWorld.setPhrase("Hello_World");
    	entityManager.persist(helloWorld);
    }

}
