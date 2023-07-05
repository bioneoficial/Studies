package br.senai.sc.controller;

import br.senai.sc.service.HelloWorldService;

import javax.inject.Inject;
import javax.inject.Named;

@Named
public class HelloWorldController {
	
	@Inject
	private HelloWorldService helloWorldService;
	
	public String getHelloWorldPhrase() {
		return helloWorldService.getHeloWorldPhrase();
	}

}
