package com.bione.bionelog.domain.service;

import com.bione.bionelog.domain.model.Delivery;
import com.bione.bionelog.domain.model.Ocurrence;
import lombok.AllArgsConstructor;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

@AllArgsConstructor
@Service
public class OcurrenceReg {

    private SearchDeliveryService searchDeliveryService;

    @Transactional
    public Ocurrence registrar(Long deliveryId, String descr) {
        Delivery delivery = searchDeliveryService.search(deliveryId);

        return delivery.addOcurrence(descr);
    }
}
