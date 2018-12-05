import dpkt

filename = 'log.pcap'
pcap_file = open(filename)
packets = dpkt.pcap.Reader(pcap_file)
_ips = set()

count = 0
instanceVariable = 0

for a,b in packets:
    print "-------------"
    try:
        ethernet = dpkt.ethernet.Ethernet(b)
        if isinstance(ethernet.data,dpkt.ip.IP):
            instanceVariable = instanceVariable + 1
            ip = ethernet.data
            tcp = ip.data
            if(dpkt.tcp.TH_SYN) != 0:
                count = count + 1
                _ips.add(ip)
                #break
    except:
        pass

print _ips
print '------------------'
print 'The Number of IP Addresses are '
print count