--- Sort an array using the tim sort algorithm.
--- @param t table
--- @return table
local function timSort(t)
    local n = #t
    local minRun = 32
    local run = {}
    local stack = {}
    local stackSize = 0
    local i = 1
    while i <= n do
        local j = i + 1
        if j <= n and t[j] < t[i] then
            while j <= n and t[j] < t[j - 1] do
                j = j + 1
            end
            local k = j - 1
            while i < k do
                t[i], t[k] = t[k], t[i]
                i = i + 1
                k = k - 1
            end
        else
            while j <= n and t[j] >= t[j - 1] do
                j = j + 1
            end
        end
        local k = j - 1
        local len = k - i + 1
        if len < minRun then
            local m = i + minRun - 1
            if m > n then
                m = n
            end
            for l = k + 1, m do
                local item = t[l]
                local p = l - 1
                while p >= i and t[p] > item do
                    t[p + 1] = t[p]
                    p = p - 1
                end
                t[p + 1] = item
            end
            k = m
        end
        run[#run + 1] = { i, k }
        stackSize = stackSize + 1
        stack[stackSize] = { i, k }
        while stackSize >= 2 do
            local p = stack[stackSize - 1]
            local q = stack[stackSize]
            if stackSize >= 3 then
                local r = stack[stackSize - 2]
                if r[2] - r[1] <= q[2] - q[1] + p[2] - p[1] then
                    if p[2] - p[1] <= q[2] - q[1] then
                        stack[stackSize - 1] = { r[1], q[2] }
                        stack[stackSize] = nil
                        stackSize = stackSize - 1
                    else
                        stack[stackSize - 2] = { r[1], p[2] }
                        stack[stackSize - 1] = { p[2] + 1, q[2] }
                        break
                    end
                else
                    break
                end
            else
                if p[2] - p[1] <= q[2] - q[1] then
                    stack[stackSize - 1] = { p[1], q[2] }
                    stack[stackSize] = nil
                    stackSize = stackSize - 1
                else
                    break
                end
            end
        end
        i = k + 1
    end
    return t
end

return timSort