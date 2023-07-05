package br.senai.sc.util;

import javax.json.bind.adapter.JsonbAdapter;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.TimeZone;

public class DataConverter {
    public static class DateDeserializer implements JsonbAdapter<Date, String> {

        private final SimpleDateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd");

        @Override
        public String adaptToJson(Date date) throws Exception {
            dateFormat.setTimeZone(TimeZone.getTimeZone("UTC"));
            return dateFormat.format(date);
        }

        @Override
        public Date adaptFromJson(String jsonDate) throws Exception {
            dateFormat.setTimeZone(TimeZone.getTimeZone("UTC"));
            Date date = dateFormat.parse(jsonDate);
            Calendar calendar = Calendar.getInstance();
            calendar.setTime(date);
            calendar.add(Calendar.DATE, 1);
            return calendar.getTime();
        }
    }
}
