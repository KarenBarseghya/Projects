class Validation
{
public:
    void set_string(std::string word);
    std::string get_string();
    bool is_valid_mail(std::string mail);
    bool is_valid_phone_number(std::string phone_number);
    bool is_valid_reference(std::string reference);
    bool is_valid_credit_card(std::string credit_card);
    bool is_valid_month_day(std::string month_day);
private:
    std::string m_word;
};
