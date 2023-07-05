package br.senai.sc.util;

import javax.json.bind.Jsonb;
import javax.json.bind.JsonbBuilder;
import javax.json.bind.JsonbConfig;
import javax.json.bind.config.PropertyNamingStrategy;


public class JsonbUtil {

    public static Jsonb createJsonb() {
        JsonbConfig config = new JsonbConfig()
                .withDateFormat("yyyy-MM-dd", null) // Configure a formatação da data
                .withPropertyNamingStrategy(PropertyNamingStrategy.LOWER_CASE_WITH_UNDERSCORES); // Configure a estratégia de nomeação de propriedades

        return JsonbBuilder.create(config);
    }
}
