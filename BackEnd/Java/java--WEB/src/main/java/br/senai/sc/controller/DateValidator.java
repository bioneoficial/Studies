package br.senai.sc.controller;

import javax.faces.application.FacesMessage;
import javax.faces.component.UIComponent;
import javax.faces.context.FacesContext;
import javax.faces.validator.FacesValidator;
import javax.faces.validator.Validator;
import javax.faces.validator.ValidatorException;
import java.util.Date;

@FacesValidator("dateValidator")
public class DateValidator implements Validator {

    @Override
    public void validate(FacesContext context, UIComponent component, Object value) throws ValidatorException {
        Date nascimento = (Date) value;
        Date hoje = new Date();

        if (nascimento != null && nascimento.after(hoje)) {
            throw new ValidatorException(new FacesMessage("A data de nascimento não pode ser maior que o dia atual."));
        }
    }
}
