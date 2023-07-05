package br.senai.sc.controller;
import javax.faces.application.FacesMessage;
import javax.faces.component.UIComponent;
import javax.faces.context.FacesContext;
import javax.faces.validator.FacesValidator;
import javax.faces.validator.Validator;
import javax.faces.validator.ValidatorException;

@FacesValidator("cpfValidator")
public class CpfValidator implements Validator<String> {

    @Override
    public void validate(FacesContext context, UIComponent component, String value) throws ValidatorException {
        if (!isValidCPF(value)) {
            FacesMessage msg = new FacesMessage(FacesMessage.SEVERITY_ERROR, "CPF inválido", "O CPF informado é inválido.");
            throw new ValidatorException(msg);
        }
    }

    private static boolean isValidCPF(String cpf) {
        if (cpf == null || cpf.length() != 11 || cpf.chars().allMatch(Character::isDigit)) {
            return false;
        }

        try {
            Long.parseLong(cpf);
        } catch (NumberFormatException e) {
            return false;
        }

        int[] digits = new int[11];
        for (int i = 0; i < 11; i++) {
            digits[i] = Character.getNumericValue(cpf.charAt(i));
        }

        int[] validationDigits = {0, 0};
        for (int i = 0; i < 9; i++) {
            validationDigits[0] += digits[i] * (10 - i);
            validationDigits[1] += digits[i] * (11 - i);
        }

        validationDigits[0] = (validationDigits[0] % 11 < 2) ? 0 : 11 - (validationDigits[0] % 11);
        validationDigits[1] += validationDigits[0] * 2;
        validationDigits[1] = (validationDigits[1] % 11 < 2) ? 0 : 11 - (validationDigits[1] % 11);

        return digits[9] == validationDigits[0] && digits[10] == validationDigits[1];
    }
}
