package jms;

import util.JMS;

import javax.ejb.ActivationConfigProperty;
import javax.ejb.MessageDriven;
import javax.jms.JMSException;
import javax.jms.Message;
import javax.jms.MessageListener;
import javax.jms.ObjectMessage;

@MessageDriven(activationConfig = {
        @ActivationConfigProperty(propertyName = "destinationType", propertyValue = JMS.VALUE_QUEUE),
        @ActivationConfigProperty(propertyName = "destination", propertyValue = TesteQueueConsumer.QUEUE_NAME),
        @ActivationConfigProperty(propertyName = "clientFailureCheckPeriod", propertyValue = "600000"),
        @ActivationConfigProperty(propertyName = "connectionTTL", propertyValue = "-1"),
        @ActivationConfigProperty(propertyName = "maxSession", propertyValue = "5"),
}, mappedName = TesteQueueConsumer.QUEUE_NAME)
public class TesteQueueConsumer implements MessageListener {

    public static final String QUEUE_NAME = "java:/jms/queue/testeQueue";

    @Override
    public void onMessage(Message message) {
        try {
            ObjectMessage object = (ObjectMessage) message;
            String texto = (String) object.getObject();
            System.out.println("Mensagem na fila -> " + texto);
        } catch (JMSException e) {
            throw new RuntimeException(e);
        }
    }
}
