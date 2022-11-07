package com.bione.bionelog.api.controller;

import com.bione.bionelog.domain.model.Client;
import com.bione.bionelog.domain.repository.ClientRepository;
import com.bione.bionelog.domain.service.CatalogClientService;
import lombok.AllArgsConstructor;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import javax.validation.Valid;
import java.util.List;

@AllArgsConstructor
@RestController
@RequestMapping("/clients")
public class ClientController {
    private ClientRepository clientRepository;
    private CatalogClientService catalogClientService;

    @GetMapping
    public List<Client> list() {
        return clientRepository.findAll();
    }

    @GetMapping("/{clientId}")
    public ResponseEntity<Client> buscar(@PathVariable Long clientId) {
        return clientRepository.findById(clientId)
                .map(ResponseEntity::ok)
                .orElse(ResponseEntity.notFound().build());
    }

    @PostMapping
    @ResponseStatus(HttpStatus.CREATED)
    public Client add(@Valid @RequestBody Client client) {
        return catalogClientService.save(client);
    }

    @PutMapping("/{clientId}")
    public ResponseEntity<Client> atualizar(@PathVariable Long clientId,
                                             @Valid @RequestBody Client client) {
        if (!clientRepository.existsById(clientId)) {
            return ResponseEntity.notFound().build();
        }

        client.setId(clientId);
        client = catalogClientService.save(client);

        return ResponseEntity.ok(client);
    }

    @DeleteMapping("/{clientId}")
    public ResponseEntity<Void> remove(@PathVariable Long clientId) {
        if (!clientRepository.existsById(clientId)) {
            return ResponseEntity.notFound().build();
        }

        catalogClientService.deleteById(clientId);

        return ResponseEntity.noContent().build();
    }
}
