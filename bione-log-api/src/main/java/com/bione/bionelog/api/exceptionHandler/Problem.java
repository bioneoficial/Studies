package com.bione.bionelog.api.exceptionHandler;

import com.fasterxml.jackson.annotation.JsonInclude;
import com.fasterxml.jackson.annotation.JsonInclude.Include;
import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.Setter;

import java.time.OffsetDateTime;
import java.util.List;

@JsonInclude(Include.NON_NULL)
@Getter
@Setter
public class Problem {
    private Integer status;
    private OffsetDateTime dataHour;
    private String title;
    private List<Field> fields;

    @AllArgsConstructor
    @Getter
    public static class Field {

        private String name;
        private String message;

    }
}
