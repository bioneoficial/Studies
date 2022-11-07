package com.bione.bionelog.domain.service;

import com.bione.bionelog.domain.model.Client;
import com.bione.bionelog.domain.model.Delivery;
import com.bione.bionelog.domain.model.DeliveryStatus;
import com.bione.bionelog.domain.repository.DeliveryRepository;
import lombok.AllArgsConstructor;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.time.OffsetDateTime;

@AllArgsConstructor
@Service
public class RequestDeliveryService {

    private CatalogClientService catalogClientService;
    private DeliveryRepository deliveryRepository;

    @Transactional
    public Delivery request(Delivery delivery) {
        Client client = catalogClientService.search(delivery.getClient().getId());

        delivery.setClient(client);
        delivery.setStatus(DeliveryStatus.PENDENTE);
        delivery.setRequest_data(OffsetDateTime.now());

        return deliveryRepository.save(delivery);
    }
}
