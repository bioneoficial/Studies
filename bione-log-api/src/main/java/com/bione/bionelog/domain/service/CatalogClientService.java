package com.bione.bionelog.domain.service;


import com.bione.bionelog.domain.exception.BusinessException;
import com.bione.bionelog.domain.model.Client;
import com.bione.bionelog.domain.repository.ClientRepository;
import lombok.AllArgsConstructor;
import org.springframework.stereotype.Service;

import javax.transaction.Transactional;

@AllArgsConstructor
@Service
public class CatalogClientService {

    private ClientRepository clientRepository;

    public Client search(Long client_id) {
        return clientRepository.findById(client_id)
                .orElseThrow(() -> new BusinessException("Cliente não encontrado"));
    }

    @Transactional
    public Client save(Client client) {
        boolean emailEmUso = clientRepository.findByEmail(client.getEmail())
                .stream()
                .anyMatch(existClient -> !existClient.equals(client));

        if (emailEmUso) {
            throw new BusinessException("Já existe um cliente cadastrado com este e-mail.");
        }

        return clientRepository.save(client);
    }

    @Transactional
    public void deleteById(Long clientId) {
        ClientRepository.deleteById(clientId);
    }

}
