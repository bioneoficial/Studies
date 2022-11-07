package com.bione.bionelog.domain.service;

import com.bione.bionelog.domain.exception.EntityNotFoundException;
import com.bione.bionelog.domain.model.Delivery;
import com.bione.bionelog.domain.repository.DeliveryRepository;

public class SearchDeliveryService {
    private DeliveryRepository deliveryRepository;

    public Delivery search(Long id_delivery) {
        return (Delivery) Delivery.findById(id_delivery)
                .orElseThrow(() -> new EntityNotFoundException("Entrega não encontrada"));
    }
}
