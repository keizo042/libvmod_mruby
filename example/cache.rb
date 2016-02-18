VCL.init do |conf|
  return VCL::Action::PASS if conf.req.http.host == "example.com" || conf.req.url == "^/admin" 
end
