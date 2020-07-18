#include <vector>
#include <string>
#include <iostream>

struct Element
{
    virtual int evaluate() const = 0;
};

struct Integer : Element
{
    int m_Value;
    Integer(const int value) : m_Value(value)
    {
    }
    int evaluate() const
    {
        return m_Value;
    }
};

struct Operation : Element
{
    enum class Type
    {
        ADDITION,
        SUBTRACTION
    };
    Type m_Type;
    std::shared_ptr<Element> m_LeftHandSide;
    std::shared_ptr<Element> m_RightHandSide;
    int evaluate() const
    {
        if (m_Type == Type::ADDITION)
        {
            return m_LeftHandSide->evaluate() + m_RightHandSide->evaluate();
        }
        return m_LeftHandSide->evaluate() - m_RightHandSide->evaluate();
    }
};

struct Token
{
    enum class Type
    {
        INTEGER,
        PLUS,
        MINUS,
        LEFT_PARENTESES,
        RIGHT_PARENTESES
    };
    Type m_Type;
    std::string m_Text;
    Token(Type type, const std::string& text)
        : m_Type(type)
        , m_Text(text)
    {
    }
};

std::vector<Token> lex(const std::string& expression)
{
    std::vector<Token> result;

    auto currentCharacter = begin(expression);
    for (currentCharacter; currentCharacter != end(expression); ++currentCharacter)
    {
        switch (*currentCharacter)
        {
            case '+':
            {
                result.emplace_back(Token::Type::PLUS, "+");
                break;
            }
            case '-':
            {
                result.emplace_back(Token::Type::MINUS, "-");
                break;
            }
            case '(':
            {
                result.emplace_back(Token::Type::LEFT_PARENTESES, "(");
                break;
            }
            case ')':
            {
                result.emplace_back(Token::Type::RIGHT_PARENTESES, ")");
                break;
            }
            default:
            {
                auto firstNotDigit = find_if(currentCharacter, end(expression), [](auto c) {
                    return !isdigit(c);
                    });
                std::string integer = std::string(currentCharacter, firstNotDigit);
                result.emplace_back(Token::Type::INTEGER, integer);
                currentCharacter = --firstNotDigit;
            }
        }
    }
    return result;
}

std::shared_ptr<Element> parse(const std::vector<Token>& tokens)
{
    auto result = std::make_unique<Operation>();

    auto currentToken = begin(tokens);
    for (currentToken; currentToken != end(tokens); ++currentToken)
    {
        switch (currentToken->m_Type)
        {
            case Token::Type::INTEGER:
            {
                if (!result->m_LeftHandSide)
                {
                    result->m_LeftHandSide = std::make_shared<Integer>(stoi(currentToken->m_Text));
                }
                else
                {
                    result->m_RightHandSide = std::make_shared<Integer>(stoi(currentToken->m_Text));
                }
                break;
            }
            case Token::Type::PLUS:
            {
                result->m_Type = Operation::Type::ADDITION;
                break;
            }
            case Token::Type::MINUS:
            {
                result->m_Type = Operation::Type::SUBTRACTION;
                break;
            }
            case Token::Type::LEFT_PARENTESES:
            {
                auto rightParenteses = find_if(currentToken, end(tokens), [](auto& token) {
                    return token.m_Type == Token::Type::RIGHT_PARENTESES;
                    });
                std::vector<Token> subExpression(currentToken + 1, rightParenteses);
                if (!result->m_LeftHandSide)
                {
                    result->m_LeftHandSide = parse(subExpression);
                }
                else
                {
                    result->m_RightHandSide = parse(subExpression);
                }
                currentToken = rightParenteses;
                break;
            }
        }
    }

    return result;
}

int main()
{
    std::cout << ":: Interpreter ::\n" << std::endl;

    std::string expression = "(15-2)-(37+2)";
    auto tokens = lex(expression);
    auto parsed = parse(tokens);
    int result = parsed->evaluate();

    std::cout << expression << " = " << result << std::endl;

    return 0;
}