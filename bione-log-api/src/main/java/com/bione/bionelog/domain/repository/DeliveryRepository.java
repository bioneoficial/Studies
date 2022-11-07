package com.bione.bionelog.domain.repository;

import com.bione.bionelog.domain.model.Delivery;
import lombok.Getter;
import lombok.Setter;
import org.springframework.data.domain.Example;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.data.domain.Sort;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.repository.query.FluentQuery;

import javax.persistence.Column;
import javax.persistence.Embeddable;
import java.util.List;
import java.util.Optional;
import java.util.function.Function;

@Getter
@Setter
@Embeddable
public class DeliveryRepository implements JpaRepository<Delivery, Long> {
    @Column(name = "name_dest")
    private String name;

    @Column(name = "log_dest")
    private String log;

    @Column(name = "number_dest")
    private String number;

    @Column(name = "comp_dest")
    private String comp_dest;

    @Column(name = "dist_dest")
    private String dist_dest;


    public List<Delivery> findAll() {
        return null;
    }

    public List<Delivery> findAll(Sort sort) {
        return null;
    }

    public Page<Delivery> findAll(Pageable pageable) {
        return null;
    }

    public List<Delivery> findAllById(Iterable<Long> longs) {
        return null;
    }

    public long count() {
        return 0;
    }

    public void deleteById(Long aLong) {

    }

    public void delete(Delivery entity) {

    }

    public void deleteAllById(Iterable<? extends Long> longs) {

    }

    public void deleteAll(Iterable<? extends Delivery> entities) {

    }

    public void deleteAll() {

    }

    public static <S extends Delivery> S save(S entity) {
        return null;
    }

    public <S extends Delivery> List<S> saveAll(Iterable<S> entities) {
        return null;
    }

    public Optional<Delivery> findById(Long aLong) {
        return Optional.empty();
    }

    public boolean existsById(Long aLong) {
        return false;
    }

    public void flush() {

    }

    public <S extends Delivery> S saveAndFlush(S entity) {
        return null;
    }

    public <S extends Delivery> List<S> saveAllAndFlush(Iterable<S> entities) {
        return null;
    }

    public void deleteAllInBatch(Iterable<Delivery> entities) {

    }

    public void deleteAllByIdInBatch(Iterable<Long> longs) {

    }

    public void deleteAllInBatch() {

    }

    public Delivery getOne(Long aLong) {
        return null;
    }

    public Delivery getById(Long aLong) {
        return null;
    }

    public Delivery getReferenceById(Long aLong) {
        return null;
    }

    public <S extends Delivery> Optional<S> findOne(Example<S> example) {
        return Optional.empty();
    }

    public <S extends Delivery> List<S> findAll(Example<S> example) {
        return null;
    }

    public <S extends Delivery> List<S> findAll(Example<S> example, Sort sort) {
        return null;
    }

    public <S extends Delivery> Page<S> findAll(Example<S> example, Pageable pageable) {
        return null;
    }

    public <S extends Delivery> long count(Example<S> example) {
        return 0;
    }

    public <S extends Delivery> boolean exists(Example<S> example) {
        return false;
    }

    public <S extends Delivery, R> R findBy(Example<S> example, Function<FluentQuery.FetchableFluentQuery<S>, R> queryFunction) {
        return null;
    }
}
