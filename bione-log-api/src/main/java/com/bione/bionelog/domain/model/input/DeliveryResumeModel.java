package com.bione.bionelog.domain.model.input;

import com.bione.bionelog.domain.model.DeliveryStatus;
import lombok.Getter;
import lombok.Setter;

import java.math.BigDecimal;
import java.time.OffsetDateTime;

@Getter
@Setter
public class DeliveryResumeModel {
    private Long id;
    private ClientResumeModel client;
    private DestinyResumeModel destiny;
    private BigDecimal tax;
    private DeliveryStatus status;
    private OffsetDateTime request_data;
    private OffsetDateTime finish_data;
}
