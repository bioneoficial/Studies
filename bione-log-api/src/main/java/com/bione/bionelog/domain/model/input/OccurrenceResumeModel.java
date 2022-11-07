package com.bione.bionelog.domain.model.input;

import lombok.Getter;
import lombok.Setter;

import java.time.OffsetDateTime;

@Getter
@Setter
public class OccurrenceResumeModel {
    private Long id;
    private String descricao;
    private OffsetDateTime dataRegistro;
}
