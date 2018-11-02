#include "parser.h"

const char *argp_program_version = "argex 1.0";

const char *argp_program_bug_address = "<bug-gnu-utils@gnu.org>";

enum parser_opts {
    //add rule
    opt_in = 0x100,
    opt_out = 0x101,
    dir_group = 0,

    //rules
    opt_proto = 0x110,
    opt_srcip = 0x130,
    opt_destip = 0x140,
    opt_srcnetmask = 0x150,
    opt_destport = 0x160,
    rule_group = 1,

    //action
    opt_action = 0x170,
    action_group = 2,

    opt_print = 0x180,
    print_group = 4,

    opt_delete = 0x190,
    delete_group = 3
};

struct argp_option options[] =
{
    {"in", opt_in, 0, 0, "Add a rule for incoming packets", dir_group},
    {"out", opt_out, 0, 0, "Add a rule for outgoing packets", dir_group},
    {"proto", opt_proto, "ALL/TCP/UDP/ICMP", 0, "Add protocol to the rule.", rule_group},
    {"srcip", opt_srcip, "valid IP", 0, "Add a source IP address to the rule.", rule_group},
    {"destip", opt_destip, "valid IP", 0, "Add a destination IP address to the rule.", rule_group},
    {"srcnetmask", opt_srcnetmask, "valid netmask", 0, "Add a source netmask to the rule.", rule_group},
    {"destport", opt_destport, "valid port number", 0, "Add a destination port number to the rule.", rule_group},
    {"action", opt_action, "BLOCK/UNBLOCK", 0, "The action to take on packets that match the given rule.", action_group},
    {"print", opt_print, 0, 0, "Print the rules.", print_group},
    {"delete", opt_delete, "rule number", 0, "Delete the given rule.", delete_group},
    {0}
};

error_t parse_opt (int key, char *arg, struct argp_state *state)
{
    struct arguments *arguments = state->input;

    switch (key)
        {
        case opt_in: //--in
            arguments->in = 1;
            break;
        case opt_out:
            arguments->out = 1;
            break;
        case opt_proto: //protocal
            arguments->proto = arg;
            break;
        case opt_srcip: //source Ip
            arguments->srcip = arg;
            break;
        case opt_destip: //destination IP
            arguments->destip = arg;
            break;
        case opt_srcnetmask: //source netmask
            arguments->srcnetmask = arg;
            break;
        case opt_destport: //port number
            arguments->port = arg;
            break;
        case opt_action: //action
            arguments->action = arg;
            break;
        case opt_print: //print
            arguments->print = 1;
            break;
        case opt_delete: //delete
            arguments->del = arg;
            break;
        default:
            return ARGP_ERR_UNKNOWN;
        }
    return 0;
}