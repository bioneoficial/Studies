package com.bione.bionelog.api.assembler;

import com.bione.bionelog.domain.model.Delivery;
import com.bione.bionelog.domain.model.input.DeliveryResumeModel;
import lombok.AllArgsConstructor;
import org.modelmapper.ModelMapper;
import org.springframework.stereotype.Component;

import java.util.List;
import java.util.stream.Collectors;

@AllArgsConstructor
@Component
public class DeliveryAssembler {
    private static ModelMapper modelMapper;

    public static DeliveryResumeModel toModel(Delivery entrega) {
        return modelMapper.map(entrega, DeliveryResumeModel.class);
    }

    public List<DeliveryResumeModel> toCollectionModel(List<Delivery> deliveries) {
        return deliveries.stream()
                .map(DeliveryAssembler::toModel)
                .collect(Collectors.toList());
    }

    public static Delivery toEntity(DeliveryResumeModel entregaInput) {
        return modelMapper.map(entregaInput, Delivery.class);
    }
}
