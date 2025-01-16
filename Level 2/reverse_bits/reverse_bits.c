unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char res = 0x0;
	int i = 0;
	while(i < 8)
	{
		res = res << 1;
		res = res | (octet & 1);
		octet = octet >> 1;
		i++;
	}
	return (res);
}
