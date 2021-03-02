
#include "../include/augdemocracy.hpp"


void augdemocracy::regsubmitter(const name submitter) {
    require_auth(submitter);
    
    auto sub = _submitters.find(submitter.value);
    uint64_t now = current_time_point().sec_since_epoch();
    if (sub == _submitters.end()) {
        _submitters.emplace(submitter, [&](submitter_info &info) {
            info.submitter = submitter;
            info.date = now;
            info.contributions = 0;
        });
    }
}


void augdemocracy::regvoter(const name voter){
    require_auth(voter);
    
    auto vot = _voters.find(voter.value);
    uint64_t now = current_time_point().sec_since_epoch();
    if (vot == _voters.end()) {
        _voters.emplace(voter, [&](voter_info &info) {
            info.voter = voter;
            info.date = now;
            info.contributions = 0;
        });
    }

}

void augdemocracy::regreviewer(const name reviewer){
    require_auth(reviewer);
    
    auto rev = _reviewers.find(reviewer.value);
    uint64_t now = current_time_point().sec_since_epoch();
    if (rev == _reviewers.end()) {
        _reviewers.emplace(reviewer, [&](reviewer_info &info) {
            info.reviewer = reviewer;
            info.date = now;
            info.contributions = 0;
        });
    }
}

void augdemocracy::regquestion(const name submitter, const std::string &quest) {
    
    require_auth(submitter);
    uint64_t now = current_time_point().sec_since_epoch();
    auto code = _self;
    auto scope = submitter;
    //auto quest =  questions_table(get_self(), submitter.value);
    
    _questions.emplace(submitter, [&](question_info &info) {  
             info.id = _questions.available_primary_key();
             info.submitter = submitter;
             info.date = now;
             //info.voted = 0;
             //info.answer = question; 
    });
    
    
}


void augdemocracy::delquestion(const name submitter, uint64_t id){
   require_auth(get_self());
   require_auth(submitter);
   auto questions = questions_table(get_self(), submitter.value);
//    auto quest = questions.find(id);
   
//    if (itr != _question.end())
//    {
//       _question.erase(itr);
//    }
}

void augdemocracy::delquestions(){ 

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

