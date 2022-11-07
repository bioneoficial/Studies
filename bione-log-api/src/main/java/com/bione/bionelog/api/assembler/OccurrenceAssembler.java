package com.bione.bionelog.api.assembler;

import com.bione.bionelog.domain.model.Ocurrence;
import com.bione.bionelog.domain.model.input.OccurrenceResumeModel;
import lombok.AllArgsConstructor;
import org.modelmapper.ModelMapper;
import org.springframework.stereotype.Component;

import java.util.List;

@AllArgsConstructor
@Component
public class OccurrenceAssembler {

    private ModelMapper modelMapper;

    public OccurrenceResumeModel toModel(Ocurrence ocurrence) {
        return modelMapper.map(ocurrence, OccurrenceResumeModel.class);
    }

    public static List<OccurrenceResumeModel> toCollectionModel(Object ocurrences) throws InterruptedException {
        return null;
    }

}
