package br.senai.sc.controller;

import br.senai.sc.model.Pessoa;
import br.senai.sc.model.Endereco;
import br.senai.sc.service.PessoaService;
import br.senai.sc.service.EnderecoService;

import javax.enterprise.context.RequestScoped;
import javax.inject.Inject;
import javax.ws.rs.*;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.Response;

@RequestScoped
@Path("/pessoas")
@Consumes(MediaType.APPLICATION_JSON)
@Produces(MediaType.APPLICATION_JSON)
public class PessoaController {

    @Inject
    private PessoaService pessoaService;

    @Inject
    private EnderecoService enderecoService;

    @POST
    public Response createPessoa(Pessoa pessoa, Endereco endereco) {
        try {
            pessoaService.criarPessoa(pessoa);
            endereco.setIdPessoa(pessoa.getIdPessoa());
            endereco.setPessoa(pessoa);
            enderecoService.criarEndereco(endereco);
            return Response.status(Response.Status.CREATED).entity("Pessoa e Endereço criados com sucesso.").build();
        } catch (Exception e) {
            return Response.status(Response.Status.BAD_REQUEST).entity(e.getMessage()).build();
        }
    }

    // Outros métodos GET, PUT, DELETE, etc.
}
