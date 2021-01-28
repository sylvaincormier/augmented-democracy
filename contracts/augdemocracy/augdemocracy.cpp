#include "augdemocracy.hpp"


void augdemocracy::regsubmitter(const name submitter) {

}


void augdemocracy::regvoter(const name voter){

}


void augdemocracy::regreviewer(const name reviewer){

}

void augdemocracy::delquestion(const name submitter, const std::string &question){

}

void augdemocracy::unregquests(){ 

}
 
void augdemocracy::unregrevs(){

}
 
void augdemocracy::unregvoters(){ 

}
    
void augdemocracy::unregquest(const name submitter, const uint64_t id){
    
}

void augdemocracy::submitinfo(const uint64_t question_id, const name voter){

}

void augdemocracy::validateinfo(const uint64_t question_id, const name voter){

}

void augdemocracy::votequestion(const uint64_t question_id, const name voter){

}

void augdemocracy::regquestion(const name submitter, const std::string &question) {
    
    // require_auth(submitter);
    
    // auto prod = _producers.find(producer.value);

    // if (prod != _producers.end()) {
    //     _producers.modify(prod, producer, [&](producer_info &info) {
    //         info.is_active = true;
    //         info.producer_name = producer_name;
    //         info.url = url;
    //         info.key = key;
    //         info.node_id = node_id;
    //         info.job_ids = job_ids;
    //     });
    // } else {
    //     _producers.emplace(producer, [&](producer_info &info) {
    //         info.owner = producer;
    //         info.total_votes = 0;
    //         info.is_active = true;
    //         info.producer_name = producer_name;
    //         info.url = url;
    //         info.key = key;
    //         info.node_id = node_id;
    //         info.job_ids = job_ids;
    //     });
    // }
}