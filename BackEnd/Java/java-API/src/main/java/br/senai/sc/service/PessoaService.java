package br.senai.sc.service;

import br.senai.sc.dao.PessoaDAO;
import br.senai.sc.model.Pessoa;

import javax.enterprise.context.ApplicationScoped;
import javax.inject.Inject;
import javax.ws.rs.NotFoundException;
import java.util.Date;
import java.util.List;
import java.util.Objects;

@ApplicationScoped
public class PessoaService {

    @Inject
    private PessoaDAO pessoaDAO;


    @Inject
    private EnderecoService enderecoService;

//    @TransactionAttribute(TransactionAttributeType.REQUIRED)
    public void criarPessoa(Pessoa pessoa) {
        if (pessoa.getEndereco() != null) {
            pessoa.getEndereco().setPessoa(pessoa);
        }
        pessoa.setCriacaoRegistro(new Date());
        pessoa.setAlteracaoRegistro(new Date());
        pessoaDAO.create(pessoa);
    }


    public void atualizarPessoa(String cpf, Pessoa pessoaAtualizada) {
        Pessoa pessoaExistente = pessoaDAO.findByCPF(cpf);
        if (pessoaExistente != null) {
            atualizarDadosPessoa(pessoaExistente, pessoaAtualizada);
            pessoaDAO.update(pessoaExistente);
        } else {
            throw new NotFoundException("Pessoa não encontrada com o CPF: " + cpf);
        }
    }

    private void atualizarDadosPessoa(Pessoa pessoaExistente, Pessoa pessoaAtualizada) {
        boolean isPessoaAtualizada = false;
        boolean isEnderecoAtualizado = enderecoService.atualizarDadosEndereco(pessoaExistente.getEndereco(), pessoaAtualizada.getEndereco());
        if (!Objects.equals(pessoaAtualizada.getNome(), pessoaExistente.getNome())) {
            pessoaExistente.setNome(pessoaAtualizada.getNome());
            isPessoaAtualizada = true;
        }
        if (!Objects.equals(pessoaAtualizada.getNascimento(), pessoaExistente.getNascimento())) {
            pessoaExistente.setNascimento(pessoaAtualizada.getNascimento());
            isPessoaAtualizada = true;
        }
        if (!Objects.equals(pessoaAtualizada.getEmail(), pessoaExistente.getEmail())) {
            pessoaExistente.setEmail(pessoaAtualizada.getEmail());
            isPessoaAtualizada = true;
        }
        if (!Objects.equals(pessoaAtualizada.getCpf(), pessoaExistente.getCpf())) {
            pessoaExistente.setCpf(pessoaAtualizada.getCpf());
            isPessoaAtualizada = true;
        }
        if (isPessoaAtualizada || isEnderecoAtualizado){
            pessoaExistente.setAlteracaoRegistro(new Date());
        }
    }


    public List<Pessoa> getAllPessoas() {
        return pessoaDAO.findAll();
    }

    public Pessoa buscarPessoaPorCPF(String cpf) {
        return pessoaDAO.findByCPF(cpf);
    }

    public void removerPessoaPorCPF(String cpf) {
        Pessoa pessoa = pessoaDAO.findByCPF(cpf);
        if (pessoa != null) {
            enderecoService.removerEnderecoPorId(pessoa.getEndereco().getIdPessoa());
            pessoaDAO.deleteByCPF(cpf);
        } else {
            throw new NotFoundException("Pessoa não encontrada");
        }
    }

}
