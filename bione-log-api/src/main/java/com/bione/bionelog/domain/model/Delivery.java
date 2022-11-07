package com.bione.bionelog.domain.model;


import com.bione.bionelog.domain.exception.BusinessException;
import lombok.EqualsAndHashCode;
import lombok.Getter;
import lombok.Setter;

import javax.persistence.*;
import java.math.BigDecimal;
import java.time.OffsetDateTime;
import java.util.ArrayList;
import java.util.Optional;

@Getter
@Setter
@EqualsAndHashCode(onlyExplicitlyIncluded = true)
@Entity
public class Delivery {

    @EqualsAndHashCode.Include
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    @ManyToOne
    private Client client;

    @Embedded
    private Destiny recipient;

    private BigDecimal taxa;

    @OneToMany(mappedBy = "delivery", cascade = CascadeType.ALL)
    private ArrayList<Ocurrence> Ocurrences = new ArrayList<>();

    @Enumerated(EnumType.STRING)
    private DeliveryStatus status;

    private OffsetDateTime request_data;

    private OffsetDateTime finish_data;

    public static Optional<Object> findById(Long entregaId) {
        return null;
    }

    public static Object getOccurrences() {
        return null;
    }

    public Ocurrence addOcurrence(String descr) {
        Ocurrence ocurrence = new Ocurrence();
        ocurrence.setDescr(descr);
        ocurrence.setReg_data(OffsetDateTime.now());
        ocurrence.setDelivery(this);

        this.getOcurrences().add(ocurrence);

        return ocurrence;
    }

    public void finalizar() {
        if (naoPodeSerFinalizada()) {
            throw new BusinessException("Entrega não pode ser finalizada");
        }

        setStatus(DeliveryStatus.FINALIZADA);
        setFinish_data(OffsetDateTime.now());
    }

    public boolean podeSerFinalizada() {
        return DeliveryStatus.PENDENTE.equals(getStatus());
    }

    public boolean naoPodeSerFinalizada() {
        return !podeSerFinalizada();
    }

}
