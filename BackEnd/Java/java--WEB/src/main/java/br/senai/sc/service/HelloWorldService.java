package br.senai.sc.service;

import br.senai.sc.dao.HelloWorldDao;
import jms.TesteQueueConsumer;
import util.JMS;

import javax.annotation.Resource;
import javax.ejb.Stateless;
import javax.inject.Inject;
import javax.jms.Queue;

@Stateless
public class HelloWorldService {

	@Inject
	private HelloWorldDao dao;

	@Inject
	private JMS jms;

	@Resource(lookup = TesteQueueConsumer.QUEUE_NAME)
	private Queue queueTeste;

	public String getHeloWorldPhrase() {
		jms.sendMessageQueue(queueTeste, "Hellow World");
		return dao.getHelloWorldPhrase();
	}
	
}
