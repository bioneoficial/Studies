package com.bione.bionelog.domain.model;

import lombok.Getter;
import lombok.Setter;

import javax.persistence.Column;
import javax.persistence.Embeddable;
import javax.persistence.Table;
import javax.validation.constraints.NotBlank;

@Getter
@Setter
@Embeddable
@Table(name = "Delivery")
public class Destiny {

    @NotBlank
    @Column(name = "name_dest")
    private String name;

    @NotBlank
    @Column(name = "log_dest")
    private String log;

    @NotBlank
    @Column(name = "number_dest")
    private String number;

    @NotBlank
    @Column(name = "comp_dest")
    private String comp_dest;

    @NotBlank
    @Column(name = "dist_dest")
    private String dist_dest;

}
