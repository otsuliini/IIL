#include "parser/parsing.hpp"

void Parser::synchronize() {
    advance();

    while (!isAtEnd()) {
        switch (peek().type_) {
            case TokenType::Number:
                break;

            case TokenType::Identifier:
                break;

            case TokenType::ivar:
                break;

            case TokenType::global:
                break;

            case TokenType::ifstatement:
                break;

            case TokenType::elsestatement:
                break;

            case TokenType::elseifstatement:
                break;

            case TokenType::dostatement:
                break;

            case TokenType::iwhile:
                break;

            case TokenType::iend:
                break;

            case TokenType::iexit:
                break;

            case TokenType::ifor:
                break;

            case TokenType::ibreak:
                break;

            case TokenType::itry:
                break;

            case TokenType::iexcept:
                break;

            case TokenType::ifinally:
                break;

            case TokenType::iexplode:
                break;

            case TokenType::ifunc:
                break;

            case TokenType::ireturn:
                break;

            case TokenType::True:
                break;

            case TokenType::False:
                break;

            case TokenType::OpenParen:
                break;

            case TokenType::CloseParen:
                break;

            case TokenType::Operator:
                break;

            case TokenType::Delimiter:
                break;

            case TokenType::Indent:
                break;

            case TokenType::FileEnd:
                break;

            case TokenType::BangEqual:
                break;

            case TokenType::EqualEqual:
                break;

            case TokenType::NONE:
                break;

            case TokenType::Greater:
                break;

            case TokenType::GreaterEqual:
                break;

            case TokenType::Less:
                break;

            case TokenType::LessEqual:
                break;

            case TokenType::Minus:
                break;

            case TokenType::Plus:
                break;

            case TokenType::Slash:
                break;

            case TokenType::Star:
                break;

            case TokenType::Bang:
                break;

            case TokenType::NIL:
                break;

            case TokenType::String:
                break;
            case TokenType::end:
                break;
            case TokenType::ior:
                break;
        }
    }
}