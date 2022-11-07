package com.bione.bionelog.domain.repository;

import com.bione.bionelog.domain.model.Client;
import org.springframework.data.domain.Example;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.data.domain.Sort;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.repository.query.FluentQuery;
import org.springframework.stereotype.Repository;

import java.util.List;
import java.util.Optional;
import java.util.function.Function;
@Repository
public class ClientRepository implements JpaRepository<Client, Long> {

    List<Client> findByName(String name) {
        return null;
    }

    List<Client> findByNameContaining(String nome) {
        return null;
    }

    public Optional<Client> findByEmail(String email) {
        return null;
    }

    public List<Client> findAll() {
        return null;
    }

    public List<Client> findAll(Sort sort) {
        return null;
    }

    public Page<Client> findAll(Pageable pageable) {
        return null;
    }

    public List<Client> findAllById(Iterable<Long> longs) {
        return null;
    }

    public long count() {
        return 0;
    }

    public static void deleteById(Long aLong) {
    }

    public void delete(Client entity) {

    }

    public void deleteAllById(Iterable<? extends Long> longs) {

    }

    public void deleteAll(Iterable<? extends Client> entities) {

    }

    public void deleteAll() {

    }

    public <S extends Client> S save(S entity) {
        return null;
    }

    public <S extends Client> List<S> saveAll(Iterable<S> entities) {
        return null;
    }

    public Optional<Client> findById(Long aLong) {
        return Optional.empty();
    }

    public boolean existsById(Long aLong) {
        return false;
    }

    public void flush() {

    }

    public <S extends Client> S saveAndFlush(S entity) {
        return null;
    }

    public <S extends Client> List<S> saveAllAndFlush(Iterable<S> entities) {
        return null;
    }

    public void deleteAllInBatch(Iterable<Client> entities) {

    }

    public void deleteAllByIdInBatch(Iterable<Long> longs) {

    }

    public void deleteAllInBatch() {

    }

    public Client getOne(Long aLong) {
        return null;
    }

    public Client getById(Long aLong) {
        return null;
    }

    public Client getReferenceById(Long aLong) {
        return null;
    }

    public <S extends Client> Optional<S> findOne(Example<S> example) {
        return Optional.empty();
    }

    public <S extends Client> List<S> findAll(Example<S> example) {
        return null;
    }

    public <S extends Client> List<S> findAll(Example<S> example, Sort sort) {
        return null;
    }

    public <S extends Client> Page<S> findAll(Example<S> example, Pageable pageable) {
        return null;
    }

    public <S extends Client> long count(Example<S> example) {
        return 0;
    }

    public <S extends Client> boolean exists(Example<S> example) {
        return false;
    }

    public <S extends Client, R> R findBy(Example<S> example, Function<FluentQuery.FetchableFluentQuery<S>, R> queryFunction) {
        return null;
    }
}
