#include <eosio/eosio.hpp>
#include <eosio/asset.hpp>
#include <eosio/symbol.hpp>
#include <eosio/transaction.hpp>
#include <cmath>
#include <algorithm>

using namespace eosio;

class [[eosio::contract("augdemocracy")]] augdemocracy: public contract {
public:
    using contract::contract;


    augdemocracy(name receiver, name code, datastream<const char *> ds) : contract(receiver, code, ds),
                                                                      _submitters(receiver, receiver.value), 
                                                                       _voters(receiver, receiver.value), 
                                                                       _reviewers(receiver, receiver.value), 
                                                                       _questions(receiver, receiver.value),
                                                                       _grids(receiver, receiver.value){}
    
    [[eosio::action]]
    void regsubmitter(const name submitter);
    
    [[eosio::action]]
    void regvoter(const name voter);

    [[eosio::action]]
    void regreviewer(const name reviewer);

    [[eosio::action]]
    void regquestion(const name submitter, const std::string &question);

    [[eosio::action]]
    void delquestion(const name submitter, uint64_t id);

     [[eosio::action]]
    void unregrevs();

     [[eosio::action]]
    void unregvoters();

    [[eosio::action]]
    void delquestions();
    
    [[eosio::action]]
    void unregquest(const name submitter, const uint64_t id);

    [[eosio::action]]
    void submitinfo(const uint64_t question_id, const name voter);

    [[eosio::action]]
    void validateinfo(const uint64_t question_id, const name voter);

    [[eosio::action]]
    void votequestion(const uint64_t question_id, const name voter);

    

    struct [[eosio::table]] submitter_info {
        name submitter;
        uint64_t date;
        double contributions = 0;

        uint64_t primary_key() const { return submitter.value; }
    };

    typedef eosio::multi_index<"submitters"_n, submitter_info> submitters_table;

    submitters_table _submitters;

    struct [[eosio::table]] voter_info {
        name voter;
        uint64_t date;
        double contributions = 0;

        uint64_t primary_key() const { return voter.value; }
    };

    typedef eosio::multi_index<"voters"_n, voter_info> voters_table;

    voters_table _voters;

    struct [[eosio::table]] reviewer_info {
        name reviewer;
        uint64_t date;
        double contributions = 0;

        uint64_t primary_key() const { return reviewer.value; }
    };

    typedef eosio::multi_index<"reviewer"_n, reviewer_info> reviewers_table;

    reviewers_table _reviewers;

    struct [[eosio::table]] question_info {
        uint64_t id;
        name submitter;
        uint64_t date;
        //double voted = 0;
        //std::vector<eosio::name> voters;
        //std::vector<bool> answers;
        //Test_Grid 
        uint64_t primary_key() const { return id; }
    };

    typedef eosio::multi_index<"questions"_n, question_info> questions_table;

    questions_table _questions;
    
    struct [[eosio::table]] grid_info {
        uint64_t id;
        name submitter;
        uint64_t date;
        
        //double voted = 0;
        //std::vector<eosio::name> voters;
        //std::vector<bool> answers;
        //Test_Grid 
        uint64_t primary_key() const { return id; }
    };

    typedef eosio::multi_index<"grids"_n, grid_info> grid_table;

    grid_table _grids;

};
