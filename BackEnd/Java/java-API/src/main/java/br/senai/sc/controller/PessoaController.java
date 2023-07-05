package br.senai.sc.controller;

import br.senai.sc.model.Pessoa;
import br.senai.sc.service.PessoaService;
import br.senai.sc.util.JsonbUtil;

import javax.enterprise.context.RequestScoped;
import javax.inject.Inject;
import javax.json.Json;
import javax.json.JsonObject;
import javax.json.JsonObjectBuilder;
import javax.ws.rs.*;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.Response;
import java.io.StringReader;
import java.util.List;
import javax.json.bind.Jsonb;
@RequestScoped
@Path("/pessoas")
@Consumes(MediaType.APPLICATION_JSON)
@Produces(MediaType.APPLICATION_JSON)
public class PessoaController {

    @Inject
    private PessoaService pessoaService;

    @POST
    public Response createPessoa(Pessoa pessoa) {
        try {
            pessoaService.criarPessoa(pessoa);
            JsonObject response = Json.createObjectBuilder()
                    .add("idPessoa", pessoa.getIdPessoa())
                    .add("mensagem", "Pessoa criada com sucesso")
                    .build();
            return Response.status(Response.Status.CREATED).entity(response).build();
        }catch (Exception e){
            return Response.status(Response.Status.BAD_REQUEST).entity(e.getMessage()).build();
        }
    }


    @PUT
    public Response updatePessoa(@QueryParam("cpf")  String cpf, Pessoa pessoaAtualizada) {
        try{
        pessoaService.atualizarPessoa(cpf, pessoaAtualizada);
            JsonObject response = Json.createObjectBuilder()
                    .add("mensagem", "Pessoa atualizada com sucesso")
                    .build();
        return Response.status(Response.Status.OK).entity(response).build();
        }catch (NotFoundException e){
            return Response.status(Response.Status.NOT_FOUND).entity(e.getMessage()).build();
        }
        catch (Exception e){
            return Response.status(Response.Status.INTERNAL_SERVER_ERROR).entity("Erro ao atualizar pessoa").build();
        }
    }


    @GET
    public Response getPessoaByCPF(@QueryParam("cpf") String cpf) {
        Pessoa pessoa = pessoaService.buscarPessoaPorCPF(cpf);
        if (pessoa == null) {
            return Response.status(Response.Status.NOT_FOUND).entity("Pessoa não encontrada").build();
        }
        try {
            Jsonb jsonb = JsonbUtil.createJsonb();
            String json = jsonb.toJson(pessoa);

            // Converter a string JSON em um JsonObject
            JsonObject jsonObject = Json.createReader(new StringReader(json)).readObject();

            // Criar um JsonObjectBuilder para a pessoa
            JsonObjectBuilder pessoaObjectBuilder = Json.createObjectBuilder();
            for (String key : jsonObject.keySet()) {
                pessoaObjectBuilder.add(key, jsonObject.get(key));
            }

            // Criar um JsonObjectBuilder para o objeto de resposta
            JsonObjectBuilder responseObjectBuilder = Json.createObjectBuilder();

            // Adicionar a pessoa ao objeto de resposta
            responseObjectBuilder.add("pessoa", pessoaObjectBuilder.build());

            // Adicionar os campos adicionais
            responseObjectBuilder.add("dataHoraInclusaoRegistro", pessoa.getCriacaoRegistro().toString());
            responseObjectBuilder.add("dataHoraUltimaAlteracaoRegistro", pessoa.getAlteracaoRegistro().toString());

            // Construir o novo JsonObject
            JsonObject updatedJsonObject = responseObjectBuilder.build();

            return Response.status(Response.Status.OK).entity(updatedJsonObject.toString()).type(MediaType.APPLICATION_JSON).build();
        } catch (Exception e) {
            return Response.status(Response.Status.INTERNAL_SERVER_ERROR).entity("Erro ao serializar a pessoa").build();
        }
    }

    @GET
    @Path("/all")
    public Response getAllPessoas() {
        List<Pessoa> pessoas = pessoaService.getAllPessoas();
        return Response.status(Response.Status.OK).entity(pessoas).build();
    }


    @DELETE
    public Response deletePessoaByCPF(@QueryParam("cpf") String cpf) {
        try {
            pessoaService.removerPessoaPorCPF(cpf);
            return Response.status(Response.Status.OK).entity("Dado de pessoa deletado com sucesso.").build();
        } catch (NotFoundException e) {
            return Response.status(Response.Status.NOT_FOUND).entity("Pessoa não encontrada.").build();
        } catch (Exception e) {
            return Response.status(Response.Status.INTERNAL_SERVER_ERROR).entity("Ocorreu um erro ao tentar remover a pessoa.").build();
        }
    }
}
