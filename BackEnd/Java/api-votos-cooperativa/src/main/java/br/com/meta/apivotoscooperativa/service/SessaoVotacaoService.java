package br.com.meta.apivotoscooperativa.service;

import br.com.meta.apivotoscooperativa.commons.enums;
import br.com.meta.apivotoscooperativa.exception.PautaNotFoundException;
import br.com.meta.apivotoscooperativa.model.Pauta;
import br.com.meta.apivotoscooperativa.model.SessaoVotacao;
import br.com.meta.apivotoscooperativa.repository.SessaoVotacaoRepository;
import jakarta.transaction.Transactional;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;

import java.util.Calendar;

@Service
@Transactional
public class SessaoVotacaoService {


    private final SessaoVotacaoRepository sessaoVotacaoRepository;


    private final PautaService pautaService;

    public SessaoVotacaoService(SessaoVotacaoRepository sessaoVotacaoRepository, PautaService pautaService) {
        this.sessaoVotacaoRepository = sessaoVotacaoRepository;
        this.pautaService = pautaService;
    }

    public Iterable<SessaoVotacao> listAllSessoes(){
        return sessaoVotacaoRepository.findAll();
    }

    @Transactional
    public SessaoVotacao saveSessaoVotacao(SessaoVotacao sessaoVotacao){
        return sessaoVotacaoRepository.save(sessaoVotacao);
    }

    public SessaoVotacao findById(Integer id) {
        return sessaoVotacaoRepository.findById(id).orElseThrow(
                () -> new PautaNotFoundException("SessaoVotacao com id " + id + " não foi encontrada.")
        );
    }

    @Transactional
    public ResponseEntity<Object> createSessao(Pauta pauta, SessaoVotacao sessao) {
        try {

            sessao.setPauta(pauta);
            Calendar calendar = Calendar.getInstance();
            calendar.add(Calendar.MINUTE, (int) sessao.getDuration().toMinutes());
            sessao.setExpireAt(calendar.getTime());
            pautaService.addSessaoVotacao(pauta, sessao);
            return ResponseEntity.status(HttpStatus.CREATED).body("Sessao " + sessao.getId() + " adicionada com sucesso.\nId da pauta: " + pauta.getId());
        } catch (Exception e) {
            return ResponseEntity.status(HttpStatus.INTERNAL_SERVER_ERROR).body(e.getMessage());
        }
    }

    @Transactional
    public ResponseEntity<String> updateSessao(Integer sessaoId, SessaoVotacao sessao) {
        try {
            sessao.setIsOpen();
            Calendar calendar = Calendar.getInstance();
            calendar.add(Calendar.MINUTE, (int) sessao.getDuration().toMinutes());
            sessao.setExpireAt(calendar.getTime());
            saveSessaoVotacao(sessao);
            Pauta pauta = pautaService.findById(sessao.getPautaId());
            pauta.setResultadoSessao(enums.PautaStatus.VOTO_ABERTO);
            pautaService.savePauta(pauta);
            return ResponseEntity.ok("SessaoVotacao com id " + sessaoId + " foi aberta.");
        } catch (PautaNotFoundException e) {
            return ResponseEntity.status(HttpStatus.NOT_FOUND).body(e.getMessage());
        } catch (Exception e) {
            return ResponseEntity.status(HttpStatus.INTERNAL_SERVER_ERROR).body("Erro ao mudar o status da SessaoVotacao " + sessaoId + ".");
        }
    }

    public boolean isSessaoOpen(SessaoVotacao sessao) {
        return sessao.getIsOpen();
    }

    public boolean isSessaoExpired(SessaoVotacao sessao) {
        if(sessao.isExpired()){
            sessao.setIsOpen();
            saveSessaoVotacao(sessao);
            return true;
        }
        return false;
    }

    public void addVoto(SessaoVotacao sessao, boolean voto) {
        if (voto) {
            sessao.setVotosSim();
        } else {
            sessao.setVotosNao();
        }
        sessao.setVotosTotal();
        saveSessaoVotacao(sessao);
    }


    public String showResult(SessaoVotacao sessao) {
        Pauta pauta = pautaService.findById(sessao.getPautaId());
        if (sessao.getIsOpen()){
            sessao.setIsOpen();
        }
        pauta.setResultadoSessao(sessao.getVotosSim() > sessao.getVotosNao() ? enums.PautaStatus.APROVADA : enums.PautaStatus.REPROVADA);
        pautaService.savePauta(pauta);
        return "SessaoVotacao " + sessao.getId() + " da pauta " + pauta.getTitulo() + " encerrada.\n" +
                "Votos Sim: " + sessao.getVotosSim() + "\n" +
                "Votos Nao: " + sessao.getVotosNao() + "\n" +
                "Votos Total: " + sessao.getVotosTotal();
                }
}
