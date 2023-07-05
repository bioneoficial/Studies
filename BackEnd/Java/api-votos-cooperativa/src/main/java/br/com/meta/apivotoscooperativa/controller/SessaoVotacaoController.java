package br.com.meta.apivotoscooperativa.controller;

import br.com.meta.apivotoscooperativa.dto.SessaoVotacaoRegisterDto;
import br.com.meta.apivotoscooperativa.dto.SessaoVotacaoVoteDto;
import br.com.meta.apivotoscooperativa.exception.PautaNotFoundException;
import br.com.meta.apivotoscooperativa.model.Associado;
import br.com.meta.apivotoscooperativa.model.AssociadoSessaoVotacao;
import br.com.meta.apivotoscooperativa.model.Pauta;
import br.com.meta.apivotoscooperativa.model.SessaoVotacao;
import br.com.meta.apivotoscooperativa.repository.AssociadoSessaoVotacaoRepository;
import br.com.meta.apivotoscooperativa.service.AssociadoService;
import br.com.meta.apivotoscooperativa.service.PautaService;
import br.com.meta.apivotoscooperativa.service.SessaoVotacaoService;
import jakarta.validation.Valid;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/sessao-votacao")
public class SessaoVotacaoController {

    private final SessaoVotacaoService sessaoVotacaoService;


    private final PautaService pautaService;


    private final AssociadoService associadoService;


    private final AssociadoSessaoVotacaoRepository associadoSessaoVotacaoRepository;

    private static final Logger logger = LoggerFactory.getLogger(SessaoVotacao.class);

    public SessaoVotacaoController(SessaoVotacaoService sessaoVotacaoService, PautaService pautaService, AssociadoService associadoService, AssociadoSessaoVotacaoRepository associadoSessaoVotacaoRepository) {
        this.sessaoVotacaoService = sessaoVotacaoService;
        this.pautaService = pautaService;
        this.associadoService = associadoService;
        this.associadoSessaoVotacaoRepository = associadoSessaoVotacaoRepository;
    }

    @GetMapping("")
    public Iterable<SessaoVotacao> listarSessoes() {
        return sessaoVotacaoService.listAllSessoes();
    }

    @PostMapping("")
    public ResponseEntity<Object> createSessao(@RequestBody SessaoVotacaoRegisterDto sessaoVotacaoRegisterDto) {
        Pauta pauta;
        SessaoVotacao sessao = new SessaoVotacao(sessaoVotacaoRegisterDto);
        sessaoVotacaoService.saveSessaoVotacao(sessao);
        Integer pautaId =  sessaoVotacaoRegisterDto.pautaId();
        try {
            pauta = pautaService.findById(pautaId);
        } catch (PautaNotFoundException e) {
            logger.error("Erro inesperado ao criar sessão: ", e);
            return ResponseEntity.status(HttpStatus.BAD_REQUEST).body("Pauta com id " + pautaId + " não foi encontrada.");
        }

        return sessaoVotacaoService.createSessao(pauta, sessao);
    }

    @PutMapping("/{sessaoId}")
    public ResponseEntity<String> openSessao(@PathVariable Integer sessaoId) {
        try {
            SessaoVotacao  sessao = sessaoVotacaoService.findById(sessaoId);
            return sessaoVotacaoService.updateSessao(sessaoId, sessao);

        } catch (PautaNotFoundException e) {
            logger.error("Erro inesperado ao criar sessão: ", e);
            return ResponseEntity.status(HttpStatus.NOT_FOUND).body(e.getMessage());
        }

    }

    @PostMapping("/{sessaoId}/votar")
    public ResponseEntity<String> voteInSession(
            @PathVariable Integer sessaoId,
            @Valid @RequestBody SessaoVotacaoVoteDto sessaoVotacaoVoteDto) {

        Integer associadoId = sessaoVotacaoVoteDto.associadoId();
        Boolean voto = sessaoVotacaoVoteDto.voto();

        try {
            SessaoVotacao sessao = sessaoVotacaoService.findById(sessaoId);
            Associado associado = associadoService.findById(associadoId);


            if (associado == null){
                return ResponseEntity.status(HttpStatus.BAD_REQUEST).body("O associado não está cadastrado");
            }
            String cpf = associado.getCpf();

            boolean isEligible = associadoService.isValidCPF(cpf);

            if (!isEligible) {
                return ResponseEntity.status(HttpStatus.BAD_REQUEST).body("Associado " + associado.getNome() +
                        " não está apto para votar.");
            }

            if (sessaoVotacaoService.isSessaoExpired(sessao) || !sessaoVotacaoService.isSessaoOpen(sessao)) {
                return ResponseEntity.status(HttpStatus.BAD_REQUEST).body("SessaoVotacao com id " + sessaoId + " está fechada.");
            }

            boolean hasVoted = associadoSessaoVotacaoRepository.existsByAssociadoAndSessaoVotacao(associado, sessao);
            if (hasVoted) {
                return ResponseEntity.status(HttpStatus.BAD_REQUEST).body("Associado  " + associado.getNome() +
                        " já votou na SessaoVotacao com id " + sessaoId);
            }

            sessaoVotacaoService.addVoto(sessao, voto);
            AssociadoSessaoVotacao associadoSessaoVotacao = new AssociadoSessaoVotacao(associado, sessao);
            associadoSessaoVotacaoRepository.save(associadoSessaoVotacao);

            return ResponseEntity.ok("Voto registrado com sucesso.");
        } catch (PautaNotFoundException e) {
            logger.error("Erro inesperado ao votar na sessão: ", e);
            return ResponseEntity.status(HttpStatus.NOT_FOUND).body(e.getMessage());
        } catch (Exception e) {
            return ResponseEntity.status(HttpStatus.INTERNAL_SERVER_ERROR).body("Erro ao votar em SessaoVotacao com id " + sessaoId);
        }
    }

    @PutMapping("/{sessaoId}/resultado")
    public ResponseEntity<String> showResult(@PathVariable Integer sessaoId) {
        try {
            SessaoVotacao sessao = sessaoVotacaoService.findById(sessaoId);
            String resultado = sessaoVotacaoService.showResult(sessao);
            return ResponseEntity.ok(resultado);
        } catch (PautaNotFoundException e) {
            logger.error("Erro inesperado ao mostrar resultado: ", e);
            return ResponseEntity.status(HttpStatus.NOT_FOUND).body(e.getMessage());
        } catch (Exception e) {
            return ResponseEntity.status(HttpStatus.INTERNAL_SERVER_ERROR).body("Error ao buscar resultado de SessaoVotacao com id " + sessaoId);
        }
    }

}
