package com.bione.bionelog.api.controller;


import com.bione.bionelog.api.assembler.DeliveryAssembler;
import com.bione.bionelog.domain.model.Delivery;
import com.bione.bionelog.domain.model.input.DeliveryResumeModel;
import com.bione.bionelog.domain.repository.DeliveryRepository;
import com.bione.bionelog.domain.service.FinishDeliveryService;
import com.bione.bionelog.domain.service.RequestDeliveryService;
import lombok.AllArgsConstructor;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import javax.validation.Valid;
import java.util.List;

@AllArgsConstructor
@RestController
@RequestMapping("/deliveries")
public class DeliveryController {
    private DeliveryRepository deliveryRepository;
    private RequestDeliveryService requestDeliveryService;
    private FinishDeliveryService finishDeliveryService;
    private DeliveryAssembler deliveryAssembler;

    @PostMapping
    @ResponseStatus(HttpStatus.CREATED)
    public DeliveryResumeModel request(@Valid @RequestBody DeliveryResumeModel deliveryResumeModel) {
        Delivery newDelivery = DeliveryAssembler.toEntity(deliveryResumeModel);
        Delivery requestedDelivery = requestDeliveryService.request(newDelivery);

        return DeliveryAssembler.toModel(requestedDelivery);
    }

    @PutMapping("/{entregaId}/finalizacao")
    @ResponseStatus(HttpStatus.NO_CONTENT)
    public void finish(@PathVariable Long deliveryId) {
        finishDeliveryService.finalizar(deliveryId);
    }

    @GetMapping
    public List<DeliveryResumeModel> list() {
        return deliveryAssembler.toCollectionModel(deliveryRepository.findAll());
    }

    @GetMapping("/{entregaId}")
    public ResponseEntity<DeliveryResumeModel> search(@PathVariable Long deliveryId) {
        return DeliveryRepository.findById(deliveryId)
                .map(delivery -> ResponseEntity.ok(DeliveryAssembler.toModel(delivery)))
                .orElse(ResponseEntity.notFound().build());
    }

}
