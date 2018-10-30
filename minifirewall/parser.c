#include "parser.h"

struct argp_option options[] =
{
    {"in", 0x100, 0, 0, "Add a rule", 0},
    {"proto", 0x200, "ALL/TCP/UDP/ICMP", 0, "Add protocol to the rule.", 1},
    {"srcip", 0x300, "valid IP", 0, "Add a source IP address to the rule.", 1},
    {"destip", 0x400, "valid IP", 0, "Add a destination IP address to the rule.", 1},
    {"srcnetmask", 0x500, "valid netmask", 0, "Add a source netmask to the rule.", 1},
    {"destport", 0x600, "valid port number", 0, "Add a destination port number to the rule.", 1},
    {"action", 0x700, "BLOCK/UNBLOCK", 0, "The action to take on packets that match the given rule.", 1},
    {"print", 0x800, 0, 0, "Print the rules.", 3},
    {"delete", 0x900, "rule number", 0, "Delete the given rule.", 2},
    {0}
};

error_t parse_opt (int key, char *arg, struct argp_state *state)
{
    struct arguments *arguments = state->input;

    switch (key)
        {
        case 0x100: //--in
            arguments->in = 1;
            break;
        case 0x200: //protocal
            arguments->proto = arg;
            break;
        case 0x300: //source Ip
            arguments->srcip = arg;
            break;
        case 0x400: //destination IP
            arguments->destip = arg;
            break;
        case 0x500: //source netmask
            arguments->srcnetmask = arg;
            break;
        case 0x600: //port number
            arguments->port = arg;
            break;
        case 0x700: //action
            arguments->action = arg;
            break;
        case 0x800: //print
            arguments->print = 1;
            break;
        case 0x900: //delete
            arguments->del = arg;
            break;
        default:
            return ARGP_ERR_UNKNOWN;
        }
    return 0;
}