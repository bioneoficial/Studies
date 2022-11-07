create table Delivery(
                         id bigint not null auto_increment PRIMARY KEY,
                         client_id bigint not null,
                         tax decimal(10,2) not null,
                         status varchar(20) not null,
                         request_data datetime not null,
                         finish_data datetime,
                         name_dest varchar(60) not null,
                         log_dest varchar(200) not null,
                         number_dest varchar(30) not null,
                         comp_dest varchar(60) not null,
                         dist_dest varchar(30) not null
);

alter table Delivery add constraint fk_client_delivery
    foreign key (client_id) references Client (id);