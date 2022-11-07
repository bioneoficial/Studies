package com.bione.bionelog.domain.service;

import com.bione.bionelog.domain.model.Delivery;
import com.bione.bionelog.domain.repository.DeliveryRepository;
import lombok.AllArgsConstructor;
import org.springframework.stereotype.Service;

import javax.transaction.Transactional;

@AllArgsConstructor
@Service
public class FinishDeliveryService {
    private DeliveryRepository deliveryRepository;
    private SearchDeliveryService searchDeliveryService;

    @Transactional
    public void finalizar(Long deliveryId) {
        Delivery delivery = searchDeliveryService.search(deliveryId);

        delivery.finalizar();

        DeliveryRepository.save(delivery);
    }
}
