#ifndef MR_TR_PARSER_C
#define MR_TR_PARSER_C

#include <stdexcept>
#include <ctype.h>
#include <iostream>

#include <maproute/tr_parser.hpp>
#include <maproute/stringhelp.hpp>
#include <maproute/input_walker.hpp>
#include <maproute/ip_convertor.hpp>


typedef enum TraceTokenKind {
    TRACE_TOKEN_SPACE, // whitespace token
    TRACE_TOKEN_NUMBER,
    TRACE_TOKEN_DOT, // the . in floating point numbers or IP addreses
    TRACE_TOKEN_MS, // ms keyword
    TRACE_TOKEN_STAR // '*' characther
} TraceTokenKind;

typedef struct TraceToken {
    TraceTokenKind kind;
    std::string contents;
} TraceToken;

typedef int (*iskind_cb)(int c);

int take_while(std::string *line, int index, iskind_cb f) {

    char c;
    std::string input = *line;
    int len = input.length();

    while (index < len && (c = input[index])) {
        if (f(c)) {
            index++;
        } else {
            return index;
        }
    }
    return index;

}

bool expect(TraceToken*self, TraceToken *other) {
    if (self->kind == other->kind) {
        return true;
    } else {
        return false;
    }
}

bool tokenize(std::string *line, std::vector<TraceToken> *out) {
    std::string input = *line;
    int len = input.length();

    for (int i = 0; i < len; i++) {
        int si = i;
        char c = input[i];
        TraceToken token;

        if (isspace(c)) {
            i = take_while(line, i, isspace);
            token.kind = TRACE_TOKEN_SPACE;
            token.contents = string_get(line, si, i);
            i--;

        } else if (isdigit(c)) {
            i = take_while(line, i, isdigit);
            token.kind = TRACE_TOKEN_NUMBER;
            token.contents = string_get(line, si, i);
            i--;

        } else if (c == '.') {
            token.kind = TRACE_TOKEN_DOT;
            token.contents = ".";

        } else if (c == '*') {
            token.kind = TRACE_TOKEN_STAR;
            token.contents = "*";

        } else if (c == 'm') {
            i++;
            c = input[i];

            if (c == 's') {
                token.kind = TRACE_TOKEN_MS;
                token.contents = "ms";
            } else {
                return false;
            }

        } else {
            return false;
        }

        if (token.kind != TRACE_TOKEN_SPACE) {
            out->push_back(token);
        }

    }

    return true;
}

bool expect(InputWalker<TraceToken> *walker, TraceTokenKind kind) {
    TraceToken token = walker->advance();

    if (token.kind == kind) {
        return true;

    } else {
        walker->backtrack();
        std::cout << "[WARNING] - Wrong token kind." << std::endl;

        return false;
    }

}

bool expect_ip(InputWalker<TraceToken> *inputs, IPV4 *out) {
    bool result;
    std::string ip_string;
    IPV4Convertor convertor;

    result = expect(inputs, TRACE_TOKEN_NUMBER);
    ip_string.append(inputs->get_current().contents);
    result = expect(inputs, TRACE_TOKEN_DOT);
    ip_string.append(inputs->get_current().contents);

    result = expect(inputs, TRACE_TOKEN_NUMBER);
    ip_string.append(inputs->get_current().contents);
    result = expect(inputs, TRACE_TOKEN_DOT);
    ip_string.append(inputs->get_current().contents);

    result = expect(inputs, TRACE_TOKEN_NUMBER);
    ip_string.append(inputs->get_current().contents);
    result = expect(inputs, TRACE_TOKEN_DOT);
    ip_string.append(inputs->get_current().contents);

    result = expect(inputs, TRACE_TOKEN_NUMBER);
    ip_string.append(inputs->get_current().contents);

    convertor.string_to_ip(&ip_string, out);

    return result;

}

bool parse_gateway(std::vector<TraceToken> *tokens, IPV4 *out) {

    InputWalker<TraceToken> inputs {*tokens};
    bool result;

    // the hop number
    result = expect(&inputs, TRACE_TOKEN_NUMBER);

    // sometimes the first number is not the hop number and it's just
    // another IP address, here we look ahead
    TraceToken look_ahead = inputs.advance();

    if (look_ahead.kind == TRACE_TOKEN_DOT) {
        // go back twice, once for the dot and another for the ip address
        // first component
        inputs.backtrack();
        inputs.backtrack();
    } else if (look_ahead.kind == TRACE_TOKEN_STAR) {
        // sometimes we get a * when we don't get a response
        return false;

    } else {
        // backtrack once to undo the look ahead
        inputs.backtrack();
    }

    // the ip address
    result = expect_ip(&inputs, out);

    return result;
}

bool TracerouteLineParser::parse(std::string *line, IPV4 *out) {

    std::vector<TraceToken> tokens;
    bool valid = tokenize(line, &tokens);

    if (valid) {
        return parse_gateway(&tokens, out);
    } else {
        return false;
    }
}

#endif
