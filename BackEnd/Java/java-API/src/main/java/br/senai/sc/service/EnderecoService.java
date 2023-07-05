package br.senai.sc.service;

import br.senai.sc.dao.EnderecoDAO;
import br.senai.sc.model.Endereco;

import javax.inject.Inject;
import java.util.Objects;

public class EnderecoService {

    @Inject
    private EnderecoDAO enderecoDAO;

    public void criarEndereco(Endereco endereco) {
        enderecoDAO.create(endereco);
    }

    public void removerEnderecoPorId(Integer id) {
        enderecoDAO.deleteById(id);
    }

    protected boolean atualizarDadosEndereco(Endereco enderecoExistente, Endereco enderecoAtualizado){
        boolean isEnderecoAtualizado = false;
        if (!Objects.equals(enderecoAtualizado.getCep(), enderecoExistente.getCep())) {
            enderecoExistente.setCep(enderecoAtualizado.getCep());
            isEnderecoAtualizado = true;
        }
        if (!Objects.equals(enderecoAtualizado.getRua(), enderecoExistente.getRua())) {
            enderecoExistente.setRua(enderecoAtualizado.getRua());
            isEnderecoAtualizado = true;
        }
        if (!Objects.equals(enderecoAtualizado.getNumero(), enderecoExistente.getNumero())) {
            enderecoExistente.setNumero(enderecoAtualizado.getNumero());
            isEnderecoAtualizado = true;
        }
        if (!Objects.equals(enderecoAtualizado.getCidade(), enderecoExistente.getCidade())) {
            enderecoExistente.setCidade(enderecoAtualizado.getCidade());
            isEnderecoAtualizado = true;
        }
        if (!Objects.equals(enderecoAtualizado.getEstado(), enderecoExistente.getEstado())) {
            enderecoExistente.setEstado(enderecoAtualizado.getEstado());
            isEnderecoAtualizado = true;
        }
        if (isEnderecoAtualizado) {
            enderecoDAO.update(enderecoExistente);
        }
        return isEnderecoAtualizado;
    }
}
