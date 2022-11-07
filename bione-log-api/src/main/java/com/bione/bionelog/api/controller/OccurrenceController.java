package com.bione.bionelog.api.controller;

import com.bione.bionelog.api.assembler.OccurrenceAssembler;
import com.bione.bionelog.domain.model.Delivery;
import com.bione.bionelog.domain.model.Ocurrence;
import com.bione.bionelog.domain.model.input.OccurrenceResumeModel;
import com.bione.bionelog.domain.service.OcurrenceReg;
import com.bione.bionelog.domain.service.SearchDeliveryService;
import lombok.AllArgsConstructor;
import org.springframework.http.HttpStatus;
import org.springframework.web.bind.annotation.*;

import javax.validation.Valid;
import java.util.List;

@AllArgsConstructor
@RestController
@RequestMapping("/deliveries/{deliveryId}/occurrences")
public class OccurrenceController {

    private SearchDeliveryService searchDeliveryService;
    private OcurrenceReg ocurrenceReg;
    private OccurrenceAssembler occurrenceAssembler;

    @PostMapping
    @ResponseStatus(HttpStatus.CREATED)
    public OccurrenceResumeModel register(@PathVariable Long deliveryId,
                                          @Valid @RequestBody OccurrenceResumeModel occurrenceResumeModel) {

        Ocurrence registeredOcurrence = ocurrenceReg
                .registrar(deliveryId, occurrenceResumeModel.getDescricao());

        return occurrenceAssembler.toModel(registeredOcurrence);

    }

    private OccurrenceResumeModel toModel(Ocurrence registeredOcurrence) {
        return null;
    }

    @GetMapping
    public List<OccurrenceResumeModel> listar(@PathVariable Long deliveryId) throws InterruptedException {
        Delivery delivery = searchDeliveryService.search(deliveryId);

        return OccurrenceAssembler.toCollectionModel(Delivery.getOccurrences());
    }

    private static List<Ocurrence> toCollectionModel(Object occurrences) {
        return null;
    }

}
