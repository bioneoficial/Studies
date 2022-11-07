create table Occurrence (
                            id bigint not null auto_increment PRIMARY KEY ,
                            id_delivery bigint not null,
                            descr text not null,
                            reg_data datetime not null
);

alter table Occurrence add constraint fk_delivery_Occurrence
    foreign key (id_delivery) references Delivery (id);