resp = Varnish::Resp.new

if(resp.http.header['Host'] == 'test.lcoal')
  return Varnish.return(Varnish::Deliver)
else
  return Varnish.return(Varnish::Fail)
end
