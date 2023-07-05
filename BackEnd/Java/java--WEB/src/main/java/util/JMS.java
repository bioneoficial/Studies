package util;

import javax.enterprise.context.ApplicationScoped;
import javax.inject.Inject;
import javax.jms.JMSConnectionFactory;
import javax.jms.JMSContext;
import javax.jms.JMSProducer;
import javax.jms.ObjectMessage;
import javax.jms.Queue;
import java.io.Serializable;
import java.util.Map;

@ApplicationScoped
public class JMS {

    public static final String VALUE_QUEUE = "javax.jms.Queue";

    @Inject
    @JMSConnectionFactory("java:/ConnectionFactory")
    private JMSContext jmsContext;

    public void sendMessageQueue(Queue queue, Serializable object) {
        try {
            JMSProducer producer = jmsContext.createProducer();
            ObjectMessage message = jmsContext.createObjectMessage();
            message.setObject(object);
            producer.send(queue, message);
        } catch (Exception e) {
            e.printStackTrace();
            throw new RuntimeException(e);
        }
    }
}
